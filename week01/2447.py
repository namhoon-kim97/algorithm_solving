def solution(n):
    if n == 1:
        return ["*"]
    stars = solution(n // 3)
    ans = []
    for star in stars:
        ans.append(star * 3)

    for star in stars:
        ans.append(star + " " * (n // 3) + star)

    for star in stars:
        ans.append(star * 3)
    print(ans)
    return ans


n = int(input())
print("\n".join(solution(n)))
