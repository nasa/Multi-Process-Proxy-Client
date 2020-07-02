
import constants as const
import ctypes
from ctypes import *
import struct
import time

def cfs_error_convert (number):
    if number < 0:
        return number + (2**32)
    else:
        return number

# init sbn_client library
ctypes.cdll.LoadLibrary('./sbn_client.so')
sbn_client = CDLL('sbn_client.so')

# init proxy_client library
ctypes.cdll.LoadLibrary('./proxy_client.so')
proxy_client = CDLL('proxy_client.so')

# create message
repeater_msg = bytearray([0x08,0x74,0xC0,0x00,0x04,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0xA5,0x08,0x0D,0x00,0x48,0x65,0x6C,0x6C,0x6F,0x20,0x54,0x68,0x65,0x72,0x65,0x21])
repeater_msg_str = str(repeater_msg)
repeater_msg_p = cast(repeater_msg_str, POINTER(c_char))
# print(repeater_msg_str)
# print(repeater_msg_p.contents)
# send repeater the end message
sbn_client.SBN_Client_Init()
sbn_client.__wrap_CFE_SB_SendMsg(repeater_msg_p)


cmd_pipe = c_ushort()
cmd_pipe_name = create_string_buffer("cmd_pipe")
status = sbn_client.__wrap_CFE_SB_CreatePipe(byref(cmd_pipe), 10, cmd_pipe_name)

msg_id = 0x18DE

status = sbn_client.__wrap_CFE_SB_Subscribe(msg_id, cmd_pipe)
print("status of __wrap_CFE_SB_Subscribe = %X" % cfs_error_convert(status))

repeater_msg = bytearray([0x08,0x74,0xC0,0x00,0x04,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0xDE,0x18,0x0D,0x00,0x48,0x65,0x6C,0x6C,0x6F,0x20,0x54,0x68,0x65,0x72,0x65,0x21])
repeater_msg_str = str(repeater_msg)
repeater_msg_p = cast(repeater_msg_str, POINTER(c_char))

# Send and receive a message
sbn_client.__wrap_CFE_SB_SendMsg(repeater_msg_p)

recv_msg_p = POINTER(c_char)()
status = sbn_client.__wrap_CFE_SB_RcvMsg(byref(recv_msg_p), cmd_pipe, const.CFE_SB_PEND_FOREVER)
assert status == 0
print("status of __wrap_CFE_SB_RcvMsg = %X" % cfs_error_convert(status))
print(recv_msg_p.contents)

# Try to just receive a message (there should be none)
recv_msg_p = POINTER(c_char)()
print("The following call should fail after 5 seconds")
status = sbn_client.__wrap_CFE_SB_RcvMsg(byref(recv_msg_p), cmd_pipe, 5000)
print("status of __wrap_CFE_SB_RcvMsg = %X" % cfs_error_convert(status))
assert status != 0 # Call should return #CFE_SB_TIME_OUT since no message should be waiting
print("If that wasn't 5 seconds, then the SBN_Client timeout is not working.")

# Test some proxy client things
print("Init the proxy client")
proxy_client.PROXY_Client_Init();

# Try to register the app
rv = proxy_client.__wrap_CFE_ES_RegisterApp();
print("Python Test: Registered? " + str(rv));


eventFilters = bytes()

eventFilters += struct.pack('hh', const.PYTHON_TEST_STARTUP_INF_EID,    0x0000)
eventFilters += struct.pack('hh', const.PYTHON_TEST_COMMAND_ERR_EID,    0x0000)
eventFilters += struct.pack('hh', const.PYTHON_TEST_COMMANDNOP_INF_EID, 0x0000)
eventFilters += struct.pack('hh', const.PYTHON_TEST_COMMANDRST_INF_EID, 0x0000)

# Register for EVS
rv = proxy_client.__wrap_CFE_EVS_Register(eventFilters,
                     len(eventFilters)/struct.calcsize('hh'),
                     # 4,
                     const.CFE_EVS_BINARY_FILTER);

rv = proxy_client.__wrap_CFE_EVS_SendEvent (const.PYTHON_TEST_STARTUP_INF_EID,
                                            const.CFE_EVS_INFORMATION,
                                            "Python Test Initialized. Version " +
                                            str(const.PYTHON_TEST_PRO_MAJOR_VERSION) + "." +
                                            str(const.PYTHON_TEST_PRO_MINOR_VERSION) + "." +
                                            str(const.PYTHON_TEST_PRO_REVISION) + "." +
                                            str(const.PYTHON_TEST_PRO_MISSION_REV));

while True:
    time.sleep(5)
    sbn_client.__wrap_CFE_SB_SendMsg(repeater_msg_p)

    time.sleep(1) # shouldn't need this sleep here, pend forever issue

    recv_msg_p = POINTER(c_char)()
    status = sbn_client.__wrap_CFE_SB_RcvMsg(byref(recv_msg_p), cmd_pipe, const.CFE_SB_PEND_FOREVER)
    print("status of __wrap_CFE_SB_RcvMsg = %X" % cfs_error_convert(status))
    print(recv_msg_p.contents)
