#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/signal.h>

/**
 * 给定一个正整数数组 nums 和一个目标正整数 target ，请找出所有可能的组合，使得组合中的元素和等于 target 。
 * 给定数组包含重复元素，每个元素只可被选择一次。请以列表形式返回这些组合，列表中不应包含重复组合。
*/

int res[9][3];
int resSize = 0;
int state[3];
int stateSize = 0;
int resColSizes[9];

void backtrack(int target, int *choices, int choicesSize, int start) {
    if (target == 0) {
        for (int i = 0; i < stateSize; ++i) {
            res[resSize][i] = state[i];
        }
        resColSizes[resSize++] = stateSize;
        return;
    }
    for (int i = start; i < choicesSize; i++) {
        if (target - choices[i] < 0) {
            continue;
        }
        // 剪枝四：如果该元素与左边元素相等，说明该搜索分支重复，直接跳过
        if (i > start && choices[i] == choices[i - 1]) {
            continue;
        }
        state[stateSize++] = choices[i];
        backtrack(target - choices[i], choices, choicesSize, i + 1);
        stateSize--;
    }
}

void subsetSumI(int *nums, int numSize, int target) {
    resSize = 0;
    int start = 0;
    backtrack(target, nums, numSize, start);
}

int main() {
    int nums[3] = {4, 4, 5};
    subsetSumI(nums, 3, 9);
    for (int i = 0; i < 9; i++) {
        bool isNotEmpty = false;
        for (int j = 0; j < 3; j++) {
            if (res[i][j] > 0) {
                printf("%d ", res[i][j]);
                isNotEmpty = true;
            }
        }
        if (isNotEmpty) {
            printf("\n");
        }
    }
    return 0;
}
