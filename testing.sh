#!/bin/bash

curl $1 \
    -X 'POST' \
    -H 'content-type: application/json' \
    -H "x-apikey: $2" \
    --data-raw "{\"$3\":\"$4\"}"
