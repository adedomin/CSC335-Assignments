// FOR http://codingbat.com/prob/p285234

void swap(int[] nums, int a, int b) {

  int temp = nums[a];
  nums[a] = nums[b];
  nums[b] = temp;
}

int partition(int[] nums, int begin, int end) {

  int pivot_index = begin;
  int pivot_value = nums[begin];
  
  for(int i = begin+1; i <= end; ++i) {
    
    if(nums[i] > pivot_value) {
    
      swap(nums, i, ++pivot_index);
    }
  }
  
  swap(nums, begin, pivot_index);
  return pivot_index;
}

public int select(int[] nums, int begin, int end, int pos) {
  
  if (begin >= end) {
  
    return nums[begin];
  }
  
  int pivot = partition(nums, begin, end);
  
  if (pivot == pos) {
  
    return nums[pivot];
  }
  else if (pivot > pos) {
  
    return select(nums, begin, pivot-1, pos);
  }
  else {
  
    return select(nums, pivot+1, end, pos);
  }
}

public int median(int[] nums) {
  
  return select(nums, 0, nums.length-1, (int)nums.length/2);
}
