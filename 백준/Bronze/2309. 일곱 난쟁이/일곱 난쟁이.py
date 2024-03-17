dwarfs = [];
for i in range(9):
    dwarfs.append(int(input()));
fake_dwarfs = [];

over = sum(dwarfs) - 100;

for i in range(len(dwarfs)):
    j = i + 1;
    for k in range(j,len(dwarfs)):
        if dwarfs[i]+dwarfs[k] == over:
            fake_dwarfs.append(dwarfs[i]);
            fake_dwarfs.append(dwarfs[k]);
            break;
    if(fake_dwarfs):
        break;
answer = list(set(dwarfs) - set(fake_dwarfs));
answer.sort();
for i in answer:
    print(i);