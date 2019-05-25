<template>
  <div>
    <h1>ahucompiler</h1>
    <hr>
    <div class="row">
      <div class="col-4">
        <b-form-input id="keyProjectNumber" v-model="keyProjectNumber" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valProjectNumber" v-model="valProjectNumber" type="text" autofocus tabindex="1"></b-form-input>
      </div>
    </div>
    <div class="row">
      <div class="col-4">
        <b-form-input id="keyClient" v-model="keyClient" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valClient" v-model="valClient" type="text" tabindex="2"></b-form-input>
      </div>
    </div>
    <div class="row">
      <div class="col-4">
        <b-form-input id="keyProjectName" v-model="keyProjectName" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valProjectName" v-model="valProjectName" type="text" tabindex="3" @keydown="toFirstAHU()"></b-form-input>
      </div>
    </div>
    <hr>
    <unit-initialisation v-if="showUnit"/>
  </div>
</template>

<script>
import UnitInitialisation from './UnitInitialisation.vue'

export default {
  name: 'GlobalInitialisation',
  components: {
    UnitInitialisation
  },
  data: function() {
    return {
      keyProjectNumber: 'Project number:',
      valProjectNumber: '',
      keyClient: 'Client:',
      valClient: '',
      keyProjectName: 'Project name:',
      valProjectName: '',
      showUnit: false
    }
  },
  methods: {
    toFirstAHU: function () {
      console.log('test')
      this.showUnit = true
    }
  },
  mounted: function () {
    var inputs = document.querySelectorAll("input,select")
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
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.row {margin: 10px 0px 0px 0px;}
h1 {margin: 0px 0px 20px 0px;}
</style>
