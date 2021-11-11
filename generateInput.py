import numpy as np

lengths = [100000, 1000000, 10000000, 100000000]

def saveList(listOfNumbers, order):
  length = len(listOfNumbers)
  filename = str(length) + '-' + order + '.txt'
  listOfNumbers.insert(0, length)


  content = ','.join([str(i) for i in listOfNumbers])

  with open("data/" + filename, 'w') as fp:
    fp.write(content)


for i in lengths:
  print("Generating lists with length", i)
  arr = np.arange(i)

  print("Generating Best Case Variation")
  best = list(arr)

  print("Generating Worst Case Variation")
  worst = list(arr[::-1])

  print("Generating Average Case Variation")
  shuffled = []

  for i in range(1):
    np.random.shuffle(arr)
    shuffled.append(list(arr))

  print("Saving to file with array length")
  saveList(best, "best")
  del best
  saveList(worst, "worst")
  del worst

  [saveList(shuffled[i], "avg-" + str(i)) for i in range(1)]
  del shuffled


