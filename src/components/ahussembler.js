// the ahu('s) assembler helps assembling those units
exports.main = (unit, inp) => {
  let input = inp

  if (unit === 'projectnumber') {
    input = '[<br>' +
              '&nbsp;&nbsp;{"project number": "'

    return [input, 'client']
  }
  else if (unit === 'client') {
    input = input + '"},<br>' +
                    '&nbsp;&nbsp;{"client": "'

    return [input, 'projectname']
  }
  else if (unit === 'projectname') {
    input = input + '"},<br>' +
                    '&nbsp;&nbsp;{"project name": "'

    return [input, 'projectname']
  }
}