pub mod reference;
pub mod student;
use std::time::{Instant};
use rand::{distributions::Uniform, Rng};

fn main() {
    let mut rng = rand::thread_rng();
    let range = Uniform::new_inclusive(0, 100);
    let arr: Vec<i32> = (0..100).map(|_| rng.sample(&range)).collect();
    let reference_result: Vec<i32> = reference::mergesort(&arr);
    let now = Instant::now();
    let student_result: Vec<i32> = student::mergesort(&arr);
    let finTime: u128 = now.elapsed().as_micros();
    if (student_result == reference_result) {
        println!("equal");
    } else {
        println!("not equal");
    }
}
