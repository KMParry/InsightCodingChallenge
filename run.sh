#!/bin/bash

cd src
make
cd ..

./src/find_anom ./log_input/batch_log.json ./log_input/stream_log.json > out.log

cd log_output
mv ../flagged_purchases.json .

