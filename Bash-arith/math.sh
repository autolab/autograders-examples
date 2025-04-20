#!/usr/bin/bash

while getopts a:b: flag
do
    case "${flag}" in
        a) X=${OPTARG};;
        b) Y=${OPTARG};;
    esac
done

echo $((X * Y))

