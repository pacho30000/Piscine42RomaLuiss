#!/bin/sh
ifconfig | grep -i Ether | cut -f 2- -d ' '