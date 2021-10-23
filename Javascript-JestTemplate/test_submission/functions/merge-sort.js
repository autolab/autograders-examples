function merge(left,right,comparator){
    let arr = [];

    while (left.length && right.length) {
        if (comparator(left[0],right[0]) == -1) {
            arr.push(left.shift());
        } else {
            arr.push(right.shift());
        }
    }
    return [ ...arr, ...left, ...right ];

}

function merge_sort(array,comparator){
    if(array.length < 2) return array;
    
    const half = array.length / 2;
    const left = array.splice(0, half);

    return merge(merge_sort(left,comparator),
                 merge_sort(array,comparator),
                 comparator);
}

module.exports = merge_sort;
