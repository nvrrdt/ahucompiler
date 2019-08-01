// the compiler acts as an interpreter constantly scanning the ahu('s) code
// and also saves the code as json after every typed '}'
exports.main = (e) => {
  console.log(e.target.innerText)
  let input = 'testen'

  console.log(input)
}