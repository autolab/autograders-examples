fn mergetwo(array1: Vec<i32>, array2: Vec<i32>) -> Vec<i32> {
    let (mut i, mut j) = (0, 0);
    let mut sorted:Vec<i32> = Vec::new();

    while i < array1.len() && j < array2.len() {
        if array1[i] < array2[j] {
            sorted.push(array1[i]);
            i += 1;
        } else {
            sorted.push(array2[j]);
            j += 1;
        }
    }

    while i < array1.len() {
        sorted.push(array1[i]);
        i += 1;
    }

    while j < array2.len() {
        sorted.push(array2[j]);
        j += 1;
    }
    return sorted;
}

fn reference_mergesort(input: &Vec<i32>, start: usize, end: usize) -> Vec<i32> {

    if start == end {
        let mut arr: Vec<i32> = Vec::new();
        arr.push(input[start]);
        return arr;
    }
    let mid: usize = start + (end-start) / 2;

    let arr1: Vec<i32> = reference_mergesort(&input, start, mid);
    let arr2: Vec<i32> = reference_mergesort(&input, mid+1, end);

    let output: Vec<i32> = mergetwo(arr1, arr2);

    return output;

}

pub fn mergesort(input: &Vec<i32>) -> Vec<i32> {
    let end: usize = input.len() -1;
    return reference_mergesort(&input, 0, end);
}