
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
  

  module.exports = bubble_sort;