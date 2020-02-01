#!/bin/bash

function test_ruby() {
    program_name=$1
    if [ -z "$program_name" ]
    then
        program_name=`basename "$PWD"`
    fi

    ls -1 inputs | while read input_file_name; do
        echo "-- Testing with input from '${input_file_name}':";
        ruby ${program_name}.rb < inputs/${input_file_name};
    done
}


test_ruby $@

