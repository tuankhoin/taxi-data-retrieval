# taxi-data-retrieval
## Introduction
This project will build up a dictionary-based data type to store information of for-hire vehicle trips in New York City using binary search tree as underlying data structure. More specific, the project will allow insertion of data, and allow search by key (typical of a dictionary).

## Specs
The data is retrieved from [the New York City Taxi & Limousine
Commission](https://www1.nyc.gov/site/tlc/about/tlc-trip-record-data.page).

The trip's pick up date and time will be the dictionary's key, and have the format `YYYY-MM-DD HH:mm:ss` (year-month-day hour:minute:second). For dupicate keys, they will be stored together in a linked list.

## How it works

### Stage 1
The search key will be put into `stdin`. The program will look up each key and output the information (the data found) to the output file specified by the second command line parameter. If the key is not found in the tree, output will be `NOTFOUND`.
The number of key comparisons performed during both successful and unsuccessful lookups will be written to `stdout`. The entries in the file do not necessarily have unique keys, so searching will locate and output all the data found for a matching key.

Example output:
`
2018-12-15 01:49:13 --> VendorID: 1 || passenger count: 1 || trip distance: 1.9 || RatecodeID: 1.0 || store and fwd flag: 0 || PULocationID: 79 || DOLocationID: 234 || payment type: 1 || fare amount: 9.5 || extra: 0.5 || mta tax: 0.5 || tip amount: 2.15 || tolls amount: 0.0 || improvement surcharge: 0.3 || total amount: 12.95 || DOdatetime: 2018-12-15 02:00:00 || trip duration: 10 ||
`

For `stdout`:
`2018-12-15 01:49:13 --> 423`

### Stage 2
This time, the key for the dictionary will be the pick up locaiton ID, and the output will be the pick up date and time. And for stage 2, in-order tree traversal is used, and outputs will be sorted in temporal order (earliest comes first).

Example output:

`79 --> 2018-12-08 19:36:57`
`79 --> 2018-12-08 21:22:08`
`79 --> 2018-12-15 01:49:13`

For `stdout`:
`79 --> 1528`

**Note**: My completed files went missing as I forgot to save them from Jupyter Notebook. The files uploaded are my first version of completion, which are only completed in structures and will have a lot of compile errors. But I will just upload them anyway so that you will know what my implement ideas are.

*Also: The project details are taken from The University of Melbourne, Department of Computing and Information Systems, 2019.*

