import numpy as np
import os

lengths = [100000, 1000000, 10000000, 100000000]

def saveList(listOfNumbers, order):
  length = len(listOfNumbers)
  filename = str(length) + '-' + order + '.txt'
  listOfNumbers.insert(0, length)

  content = ','.join([str(i) for i in listOfNumbers])

  if not os.path.exists("data"): os.mkdir("data") 

  with open("data/" + filename, 'w+') as fp:
    fp.write(content)

for i in lengths:
  print("Generating lists with length", i)
  arr = np.arange(i)

  print("Generating Best Case Variation")
  best = list(arr)

  print("Saving best to file with array length")
  saveList(best, "best")
  del best

  print("Generating Worst Case Variation")
  worst = list(arr[::-1])
  saveList(worst, "worst")
  del worst

  print("Generating Average Case Variation")
  np.random.shuffle(arr)
  shuffled = list(arr)
  saveList(shuffled, "avg")

  del shuffled
  del arr
