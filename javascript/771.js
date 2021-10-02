const numJewelsInStones = (J, S) => {
  let obj = {}, res = 0
  for (let letter of J) {
    obj[letter] = true
  }
  for (letter of S) {
    if (obj[letter]) res++
  }
  return res
}