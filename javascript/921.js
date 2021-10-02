const minAddToMakeValid = (S) => {
  const reg = /\(\)/g
  while (reg.test(S)) S = S.replace(reg, "")
  return S.length
};