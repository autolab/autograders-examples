function sum(a, b) {
    return a + b;
}

// in place bubble sort
function bubble_sort(array,comparator){
  let swapped = false;
  do{
    swapped = false;
    for (let i=0; i < array.length - 1; i++){
      if(comparator(array[i],array[i+1]) == 1){
        const a=array[i], b=array[i+1];
        array[i+1] = a;
        array[i] = b;
        swapped = true;
      }
    }
  } while(swapped);

  return array;
}

function merge(left,right,comparator){
  let arr = []
  while (left.length && right.length) {
      if (comparator(left[0],right[0]) == -1) {
          arr.push(left.shift())  
      } else {
          arr.push(right.shift()) 
      }
  }
  return [ ...arr, ...left, ...right ]
}

function merge_sort(array,comparator){

  const half = array.length / 2;
  
  if(array.length < 2){
    return array;
  }
  const left = array.splice(0, half);

  return merge(merge_sort(left,comparator),merge_sort(array,comparator),comparator);
}

module.exports = {sum, bubble_sort, merge_sort};