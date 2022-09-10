Using start < end and start <= end are just two of the many different ways to implement BS. The key difference is how the search terminates. In case of start <= end, we usually compare mid value to the given target inside the while loop, and terminate early if target is found.

In case of start < end, the loop terminates when start == end.
The start < end method is faster compared to the start <= end (yeah the one that terminates early is actually slower) because in the start <= end case, for every iteration of the while loop, there is that extra if condition which checks mid value to target.

However in the start < end case, this check is done only once when the loop terminates ex: nums[lo] == target or something similar (nums[hi] is also fine) . For this, the cost is 1 extra loop iteration.
