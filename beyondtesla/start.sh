#!/bin/bash

echo "=========================="
echo "Starting App beyondtesla for {APP_PRETTY_NAME}"


systemctl start beyondtesla
systemctl start rosnodeChecker
