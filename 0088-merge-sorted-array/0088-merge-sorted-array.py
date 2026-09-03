class Solution:
    def merge(self, nums1, m, nums2, n):

        # Treat nums1[:m] + nums2 as one virtual array
        length = m + n

        # Initial gap = ceil(length / 2)
        gap = (length // 2) + (length % 2)

        while gap > 0:

            left = 0
            right = left + gap

            while right < length:

                # CASE 1:
                # Both elements are in nums1
                if left < m and right < m:

                    if nums1[left] > nums1[right]:
                        nums1[left], nums1[right] = (
                            nums1[right],
                            nums1[left]
                        )

                # CASE 2:
                # left is in nums1
                # right is in nums2
                elif left < m and right >= m:

                    if nums1[left] > nums2[right - m]:
                        nums1[left], nums2[right - m] = (
                            nums2[right - m],
                            nums1[left]
                        )

                # CASE 3:
                # Both elements are in nums2
                else:

                    if nums2[left - m] > nums2[right - m]:
                        nums2[left - m], nums2[right - m] = (
                            nums2[right - m],
                            nums2[left - m]
                        )

                left += 1
                right += 1

            # Stop after gap = 1
            if gap == 1:
                break

            # Next gap = ceil(gap / 2)
            gap = (gap // 2) + (gap % 2)

        # nums1[:m] now contains the smallest m elements
        # nums2 contains the remaining n largest elements

        for i in range(n):
            nums1[m + i] = nums2[i]


        