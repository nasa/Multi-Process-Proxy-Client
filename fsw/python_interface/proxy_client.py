#
# GSC-18364-1, "Proxy Core Flight System Application and Client for External Process"
#
# Copyright © 2019-2022 United States Government as represented by
# the Administrator of the National Aeronautics and Space Administration.
# All Rights Reserved.
#
# Licensed under the NASA Open Source Agreement version 1.3
# See "NOSA GSC-18364-1.pdf"
#

import ctypes
from ctypes import *
import constants as const
import struct

proxy_client = None

def proxy_load_and_init():
    global proxy_client

    ctypes.cdll.LoadLibrary('./proxy_client.so')
    proxy_client = CDLL('proxy_client.so')
    print("Proxy Client library loaded: '{}'".format(proxy_client))
    status = proxy_client.PROXY_Client_Init();
    print("Proxy Client init: {}".format(status))

def proxy_es_registerapp():
    global proxy_client

    status = proxy_client.__wrap_CFE_ES_RegisterApp()
    print("Proxy ES Register App: {}".format(status))

def proxy_evs_register():
    eventFilters = bytes()

    eventFilters += struct.pack('hh', const.PYTHON_TEST_STARTUP_INF_EID,    0x0000)
    eventFilters += struct.pack('hh', const.PYTHON_TEST_COMMAND_ERR_EID,    0x0000)
    eventFilters += struct.pack('hh', const.PYTHON_TEST_COMMANDNOP_INF_EID, 0x0000)
    eventFilters += struct.pack('hh', const.PYTHON_TEST_COMMANDRST_INF_EID, 0x0000)

    # Register for EVS
    status = proxy_client.__wrap_CFE_EVS_Register(eventFilters,
                                                  len(eventFilters)/struct.calcsize('hh'),
                                                  # 4,
                                                  const.CFE_EVS_BINARY_FILTER)
    print("Proxy EVS Register: {}".format(status))

def proxy_evs_sendevent(message):
    # TODO: should check if registered first
    print("Message: " + message)
    status = proxy_client.__wrap_CFE_EVS_SendEvent(const.PYTHON_TEST_STARTUP_INF_EID,
                                                   const.CFE_EVS_INFORMATION,
                                                   message + " Version " +
                                                   str(const.PYTHON_TEST_PRO_MAJOR_VERSION) + "." +
                                                   str(const.PYTHON_TEST_PRO_MINOR_VERSION) + "." +
                                                   str(const.PYTHON_TEST_PRO_REVISION) + "." +
                                                   str(const.PYTHON_TEST_PRO_MISSION_REV))
