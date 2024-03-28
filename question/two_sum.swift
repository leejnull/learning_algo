func twoSumHashTable(nums: [Int], target: Int) -> [Int] {
    var dic: [Int: Int] = [:]
    for i in nums.indices {
        if let j = dic[target - nums[i]] {
            return [j, i]
        }
        dic[nums[i]] = i
    }
    return [0]
}

let res = twoSumHashTable(nums: [2, 7, 11, 15], target: 13)
print("\(res)")

