def solution(enter, leave):
    answer = []
    l = []
    meet_list = [[0 for col in range(len(enter))] for row in range(len(enter))]

    enter_idx, leave_idx = 0, 0
    while (enter_idx < len(enter) and leave_idx < len(leave)):
        if (enter[enter_idx] != leave[leave_idx]):
            while (enter_idx < len(enter) and enter[enter_idx] != leave[leave_idx]):
                l.append(enter[enter_idx])
                enter_idx += 1
        if (enter[enter_idx] == leave[leave_idx]):
            for num in l:
                for s_num in l:
                    if (num == s_num): continue
                    meet_list[num - 1][s_num - 1] = 1
        enter_idx += 1;
        leave_idx += 1
    print(meet_list)
    return answer

print(solution([1,4,2,3],[2,1,4,3]))