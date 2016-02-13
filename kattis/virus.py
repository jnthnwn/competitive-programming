from sys import exit

s1 = input()
s2 = input()

# there are only characters inserted into s1, print length difference
if s1 in s2:
  print(len(s2) - len(s1))
  exit()

# determine index of char where s1 and s2 first differ
begin = 0
while begin < len(s1) and begin < len(s2) and s1[begin] == s2[begin]:
  begin += 1

# same as above, except from the end of s1 and s2
end1 = len(s1) - 1
end2 = len(s2) - 1
while end1 >= 0 and end2 >= 0 and s1[end1] == s2[end2]:
  end1 -= 1
  end2 -= 1

# if the indices in s2 cross, then nothing could have been inserted
if end2 < begin:
  print(0)
# otherwise just print out the index difference
else:
  print(end2 - begin + 1)
