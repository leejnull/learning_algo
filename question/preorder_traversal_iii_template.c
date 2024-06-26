#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "build_tree.h"

TreeNode *path[7];
TreeNode *res[7][7];
int pathSize = 0;
int resSize = 0;

/* 判断当前状态是否为解 */
bool isSolution() {
    return pathSize > 0 && path[pathSize - 1]->val == 7;
}

/* 记录解 */
void recordSolution() {
    for (int i = 0; i < pathSize; i++) {
        res[resSize][i] = path[i];
    }
    resSize++;
}

/* 判断在当前状态下，该选择是否合法 */
bool isValid(TreeNode *choice) {
    return choice != NULL && choice->val != 3;
}

/* 更新状态 */
void makeChoice(TreeNode *choice) {
    path[pathSize++] = choice;
}

/* 恢复状态 */
void undoChoice() {
    pathSize--;
}

/* 回溯算法模板 */
void backtrack(TreeNode *choices[2]) {
    // 检查是否为解
    if (isSolution()) {
        // 记录解
        recordSolution();
    }
    // 遍历所有选择
    for (int i = 0; i < 2; i++) {
        TreeNode *choice = choices[i];
        // 剪枝：检查选择是否合法
        if (isValid(choice)) {
            // 尝试：做出选择，更新状态
            makeChoice(choice);
            // 进行下一轮
            TreeNode *nextChoices[2] = {choice->left, choice->right};
            backtrack(nextChoices);
            // 回退：撤销选择，恢复到之前的状态
            undoChoice();
        }
    }
}
