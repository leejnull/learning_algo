func backtrack(nums: [Int], states: inout [Int], res: inout [[Int]]) {
    if (states.count == nums.count) {
        res.append(states)
        return
    }
    for choice in nums {
        if (!states.contains(choice)) {
            states.append(choice)
            backtrack(nums: nums, states: &states, res: &res)
            states.removeLast()
        }
    }
}

func permutationsI() {
    var res: [[Int]] = []
    var states: [Int] = []
    backtrack(nums: [1,2,3], states: &states, res: &res)
    print(res)
}

permutationsI()
