import sys


def make_second(time):
    min, sec = map(int, time.split(":"))
    return min * 60 + sec


n = int(input())
team1 = 0
team2 = 0
score1 = 0
score2 = 0
arr = []
for _ in range(n):
    a, b = input().split()
    arr.append([a, b])
arr.append(["0", "48:00"])
for i, team in enumerate(arr):
    if i == len(arr) - 1:
        break
    if team[0] == "1":
        score1 += 1
    elif team[0] == "2":
        score2 += 1

    if score1 > score2:
        team1 += make_second(arr[i + 1][1]) - make_second(team[1])
    elif score1 < score2:
        team2 += make_second(arr[i + 1][1]) - make_second(team[1])

formatted_time1 = "{:02}:{:02}".format(team1 // 60, team1 % 60)
formatted_time2 = "{:02}:{:02}".format(team2 // 60, team2 % 60)
print(formatted_time1)
print(formatted_time2)
