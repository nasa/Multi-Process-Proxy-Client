# Multi-Process Proxy (MPP) Requirements

Multi-Process Proxy includes the [Proxy](https://aetd-git.gsfc.nasa.gov/cFS_lab/proxy), [Proxy Client](https://aetd-git.gsfc.nasa.gov/cFS_lab/proxy_client), and [Proxy EVS](https://aetd-git.gsfc.nasa.gov/cFS_lab/proxy_evs) application.
A demonstration application is also provided: [CLIP](https://aetd-git.gsfc.nasa.gov/cFS_lab/clip).

Refer to git commits for document history and revisions.

The primary requirement of the software is that it must enable cFS applications to be executed as a "Process Application."
A Process Application is launched in a separate process than the rest of cFS and maintains the behavior and functionality of a normal cFS application.
Fulfillment of this requirement is confirmed via functional testing with demonstration projects such as the CLIP ([demonstration cFS](https://aetd-git.gsfc.nasa.gov/cFS_lab/cfs_mps/-/tree/clip_demo)

## 1. Provide Access to Select cFS Functions

The MPP will provide applications to selected cFS functions as defined in [cfs_api.fbs](https://aetd-git.gsfc.nasa.gov/cFS_lab/proxy_client/-/blob/master/interface/cfs_api.fbs).
These functions are those that alter cFS global state (and thus can _not_ be satisfied by linking cFS as a library) but is not exhaustive.
Future versions of this software may support more functions. 

## 2. Provide a Mechanism for cFS to Control the Process Application

cFS shall be able to control the Process Application as if it were a normal cFS application.
This functionality is provided by the Proxy application.

## 3. Relay EVS Messages for Proxy

The Process Application will have access to EVS to send event messages.
The Proxy application shall be able to send event messages in a secondary channel to prevent confusion (provided by Proxy EVS).

## 4. Build for cFS Applications

MPP shall support building and linking as a library for cFS applications that are isolated from cFS as an external process.

## 5. Language Support

MPP shall provide bindings for applications written in Python to utilize it.
