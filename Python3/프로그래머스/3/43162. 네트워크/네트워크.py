from collections import deque

def solution(n, computers):
    answer = 0
    visited = [False] * n
    for i in range(n):
        if visited[i] == False:
            visited[i] = True
            q = deque()
            q.append(i)
            answer += 1
            while q:
                cur = q.popleft()
                for idx, a in enumerate(computers[cur]):
                    if a == 1 and visited[idx] == False:
                        q.append(idx)  
                        visited[idx] = True
                
    return answer