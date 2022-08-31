# Rust-Mergesort: An autograder for Rust (using Rust!)

### Assessment Language
[Rust](https://www.rust-lang.org/)

### Autograder Language
[Rust](https://www.rust-lang.org/)

### Autograding Environment Packages
[Rust Official Docker Image](https://hub.docker.com/_/rust)

### Assessment Scenario
Students need to create a mergesort implementation in Rust that returns a sorted Vector, given a Vector of `i32`s.

### Handin Format
`student.rs` (look at Installation Instructions for more info)

### autograder.tar Directory Content
```
# extracts autograde directory and compiles and runs autograder
Makefile
# Autolab top-level autograder
src/main.rs
# Autolab lower-level autograder
autograde/src/main.rs
# Dockerfile for custom rust image
Dockerfile_rust
# reference student solution
student.rs
# dependencies, project defintion
Cargo.toml
Cargo.lock
```

## Disclaimer
This autograder was written by someone whose first experience working with rust was through this project, so it may not incorporate best practices for rust code.

## Overview
This is an autograder that purely makes use of Rust to autograde a mergesort function written in Rust (along with a makefile). This is done by using Rust's package manager, Cargo. When the main rust project, rust-mergesort, is built and run (via the makefile), the `main` function will execute `cargo run` on the subproject `autograde`, which contains the driver code (in `autograde/main.rs`) to run tests and compare results between the reference code (`reference.rs`) and the student's code (`student.rs`). When the driver code has finished running, the `main` of the top level `rust-mergesort` then searches `stdout` for the results of the driver, to then generate the final JSON scores. A custom docker image is needed for the autograder to work, with the image based off the offical rust docker image.

## Installation instructions

1. Copy `Dockerfile_rust` into your Tango directory, and read the instructions in the file to get the image built
2. Create a new assessment by going to "Install Assessment," and using the Assessment Builder, specify the assessment name and category
3. After creating the assessment, go to "Edit Assessment," and add an autograder module by scrolling to the bottom and clicking plus next to the "Autograder" option
4. In Autograder settings, specify the VM image to be "autograding_rust" (or whatever name you specified when building the docker image), and choose the autograder makefile to be the Makefile in this repository, and use `autograde.tar` for the autograder tar, and then save your settings
6. Go back to "Edit Assessment," click on the "Handin" tab, and specify the handin filename to be "student.rs"
7. Go to "problems," click "Add Problem," and add a problem with the name "correctness" and specify a max score of 100. You should now be able to upload your solution to Autolab!
8. Solution files should implement this function to return a sorted list as the autograder will attempt to call it to grade your solution:
    ```rust
    pub fn mergesort(input: &Vec<i32>) -> Vec<i32> {
    }
    ```

## To be improved:
- The grading portion is extremely simple, with the only check being against a single array of 100 elements, with the elements being randomly generated at runtime. There could definitely be more comprehensive tests, such as for the speed of the function using time.
- Currently, autograding is slow because whenever a file is submitted, Cargo searches for all crates and has to install them, which adds significant time (right now jobs take around 20 seconds). I tried running `cargo search` which indexes crates.io as part of the Dockerfile, which would theoretically speed this step, but then this somehow results in a permission denied error when downloading crates. There should possibly another, more efficient way of installing and compiling libraries.