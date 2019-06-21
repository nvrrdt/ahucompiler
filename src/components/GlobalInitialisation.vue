<template>
  <div>
    <h1>ahucompiler</h1>
    <hr>
    <div class="row">
      <div class="col-3">
        <span>{{ keyProjectNumber }}</span>
      </div>
      <div class="col-9">
        <span id="valProjectNumber" contenteditable="true" tabindex="1" @keyup="updateInputProjectNumber" ref="autofocus"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyClient }}</span>
      </div>
      <div class="col-9">
        <span id="valClient" contenteditable="true" tabindex="2" @keyup="updateInputClient"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyProjectName }}</span>
      </div>
      <div class="col-9">
        <span id="valProjectName" contenteditable="true" tabindex="3" @keyup="updateInputProjectName" @keydown.enter="$parent.$emit('onAddFormElement', 'UnitInitialisation')"></span>
      </div>
    </div>
    <hr>
  </div>
</template>

<script>
export default {
  name: 'GlobalInitialisation',
  data: function() {
    return {
      keyProjectNumber: 'Project number:',
      valProjectNumber: '',
      keyClient: 'Client:',
      valClient: '',
      keyProjectName: 'Project name:',
      valProjectName: '',
    }
  },
  methods: {
    updateInputProjectNumber: function () {
      this.valProjectNumber = document.getElementById("valProjectNumber").innerText
      console.log(this.valProjectNumber)
    },
    updateInputClient: function () {
      this.valClient = document.getElementById("valClient").innerText
      console.log(this.valClient)
    },
    updateInputProjectName: function () {
      this.valProjectName = document.getElementById("valProjectName").innerText
      console.log(this.valProjectName)
    }
  },
  mounted: function () {
    var inputs = document.querySelectorAll("span")
    for (var i = 0 ; i < inputs.length; i++) {
      inputs[i].addEventListener("keypress", function(e){
          if (e.which == 13) {
            e.preventDefault()
            var nextInput = document.querySelectorAll('[tabIndex="' + (this.tabIndex + 1) + '"]')
            if (nextInput.length === 0) {
                nextInput = document.querySelectorAll('[tabIndex="1"]')
            }
            nextInput[0].focus();
          }
      })
    }

    // autofocus
    this.$refs.autofocus.focus()
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.row {margin: 10px 0px 0px 0px;}
h1 {margin: 0px 0px 20px 0px;}
</style>
