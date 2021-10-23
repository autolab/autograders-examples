const sum = require('./functions/sum');
const bubble_sort = require('./functions/bubble-sort');
const merge_sort = require('./functions/merge-sort');

const int_comparator = (a, b) => {
  if (a > b) return 1;
  if (a == b) return 0;
  return -1;
}

test('adds 1 + 2 to equal 3', () => {
  expect(sum(1, 2)).toBe(3);
});

test('adds 3 + 4 to equal 7', () => {
  expect(sum(3, 4)).toBe(7);
});

test('bubble_sort sorts array', () => {
  expect(bubble_sort([3,2,1],int_comparator)).toMatchObject([1,2,3]);
});

test('bubble_sort should be ~n^2', () => {
  
  // creates a mock function that we can track stats of
  // https://jestjs.io/docs/mock-functions
  const mock_comparator = jest.fn(int_comparator);

  const array_length = Math.floor(Math.random() * 100);
  const input_array = Array.from({length: array_length}, () => Math.floor(Math.random() * 100));
  const buffer = 1;

  // sort using default javascript sort
  const sorted_array = [...input_array].sort(int_comparator);
  const result_arary = bubble_sort(input_array,mock_comparator);
  
  expect(result_arary).toMatchObject(sorted_array);

  // checking the number of comparisons made
  expect(mock_comparator.mock.calls.length).toBeLessThan((array_length + buffer)**2);
});

test('merge_sort sorts array', () => {
  expect(merge_sort([3,1,2,3,4],int_comparator)).toMatchObject([1,2,3,3,4]);
});

test('merge_sort should be ~nlogn', () => {
  const mock_comparator = jest.fn(int_comparator);
  const array_length = Math.floor(Math.random() * 100);
  const input_array = Array.from({length: array_length}, () => Math.floor(Math.random() * 100));
  const buffer = 1;

  const sorted_array = [...input_array].sort(int_comparator);
  const result_arary = merge_sort(input_array,mock_comparator);
  
  expect(result_arary).toMatchObject(sorted_array);
  expect(mock_comparator.mock.calls.length).toBeLessThan((array_length+buffer)*Math.log2(array_length+buffer));
});

