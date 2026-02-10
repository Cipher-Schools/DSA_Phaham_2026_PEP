package 03_Two_Pointer.Common_elements;

public class commpn_in_3_sorted_arrays {
 
  
  // Approach - 1 | 3-pointers | TC - O(n), SC - O(1)
      public List<Integer> commonElements(int[] arr1, int[] arr2, int[] arr3) {

        int n1 = arr1.length, n2 = arr2.length, n3 = arr3.length;
        int i = 0, j = 0, k = 0;

        List<Integer> res = new ArrayList<>();
        int last = Integer.MIN_VALUE;   // To avoid duplicates

        while (i < n1 && j < n2 && k < n3) {

            // If elements are same in all arrays
            if (arr1[i] == arr2[j] && arr1[i] == arr3[k] && arr1[i] != last) {
                res.add(arr1[i]);
                last = arr1[i];
                i++; j++; k++;
            }
            // Move pointer of smallest element
            else {
                int minVal = Math.min(arr1[i], Math.min(arr2[j], arr3[k]));

                if (arr1[i] == minVal) i++;
                else if (arr2[j] == minVal) j++;
                else k++;
            }
        }

        return res;
    }
    
  // Approach - 2 | Using HashSet | TC - O(n), SC - O(n)
     public List<Integer> commonElements(List<Integer> arr1, List<Integer> arr2,
                                        List<Integer> arr3) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        int n3 = arr3.size();
        ArrayList<Integer> list;
        Set<Integer> sc1=new LinkedHashSet<Integer>();
        Set<Integer> sc2=new LinkedHashSet<Integer>();
        for(int i=0;i<n1;i++)
        {
            sc1.add(arr1[i]);
        }
        for(int i=0;i<n2;i++)
        {
            if(sc1.contains(arr2[i]))
            {
                sc2.add(arr2[i]);
            }
        }
        sc1.clear();
        for(int i=0;i<n3;i++)
        {
            if(sc2.contains(arr3[i]))
            {
                sc1.add(arr3[i]);
            }
        }
        list=new ArrayList<Integer>(sc1);
        return list;
    }
}
