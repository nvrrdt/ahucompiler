<template>
  <div id="app">
    <div class="row justify-content-center">
      <div class="col-6">
        <div>
          <button type="button" class="btn btn-outline-primary" @click="ahussemble()">New</button>
          <button type="button" class="btn btn-outline-primary">Save as</button>
        </div>
        <div>
          <span id="inputspan" contenteditable="true" @keydown="onKeydown($event)">{{ input }}</span>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
var ahucompiler = require('./components/ahucompiler.js')
var ahussembler = require('./components/ahussembler.js')

export default {
  name: 'app',
  data: function() {
    return {
      input: '',
      assembly: ['projectnumber']
    }
  },
  methods: {
    onKeydown: function (e) {
      // compiling of the ahu('s) code permanently as an interpreter
      

      if (e.which === 13) { // 13 == return
        e.preventDefault()
        this.ahussemble()
        ahucompiler.main(e)
      }
      else if (e.which === 8) { // 8 == backspace
        e.preventDefault()
        this.input = this.input.substr(0, this.input.length-1)
      }
      else {
        let inp = String.fromCharCode(event.keyCode)
        if (/[a-zA-Z0-9-_ ]/.test(inp)) {
          this.input = this.input + e.key
        }
        console.log(this.input)
      }
      return false
    },
    ahussemble: function () {
      // assemble the code for the ahu('s)
      let result = ahussembler.main(this.assembly[this.assembly.length - 1], this.input)
      this.input = result[0]
      this.assembly.push(result[1])
      console.log(this.assembly)
      this.setCaretToEnd(document.getElementById('inputspan'))
    },
    setCaretToEnd: function (target/*: HTMLDivElement*/) {
      const range = document.createRange();
      const sel = window.getSelection();
      range.selectNodeContents(target);
      range.collapse(false);
      sel.removeAllRanges();
      sel.addRange(range);
      target.focus();
      range.detach(); // optimization

      // set scroll to the end if multiline
      target.scrollTop = target.scrollHeight; 
    }
  },
  mounted: function () {
    // autofocus
    //this.$refs.autofocus.focus()
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: left;
  color: #2c3e50;
  margin-top: 20px;
}

.btn {
  margin: 5px 5px 20px 5px;
}

[contenteditable]:focus {
    outline: 0px solid transparent;
}
</style>
