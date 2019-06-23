<template>
  <div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyDamper }}</span>
      </div>
      <div class="col-9">
        <span id="valDamper" contenteditable="true" tabindex="17" @keyup="updateInputDamper"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyFlexibleConnection }}</span>
      </div>
      <div class="col-9">
        <span id="valFlexibleConnection" contenteditable="true" tabindex="18" @keyup="updateInputFlexibleConnection"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyPlacementDamper }}</span>
      </div>
      <div class="col-9">
        <span id="valPlacementDamper" contenteditable="true" tabindex="19" @keyup="updateInputPlacementDamper" @keydown.enter="$parent.$emit('onAddFormElement', 'Autocomplete')"></span>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: 'Register',
  data: function() {
    return {
      keyDamper: 'Type of damper:',
      valDamper: '',
      keyFlexibleConnection: 'Flexible connection:',
      valFlexibleConnection: '',
      keyPlacementDamper: 'Placement of damper:',
      valPlacementDamper: ''
    }
  },
  methods: {
    updateInputDamper: function () {
      this.valDamper = document.getElementById("valDamper").innerText
      console.log(this.valDamper)
    },
    updateInputFlexibleConnection: function () {
      this.valFlexibleConnection = document.getElementById("valFlexibleConnection").innerText
      console.log(this.valFlexibleConnection)
    },
    updateInputPlacementDamper: function () {
      this.valPlacementDamper = document.getElementById("valPlacementDamper").innerText
      console.log(this.valPlacementDamper)
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
  }
}
</script>

<style>
.row {margin: 15px 0px 0px 0px;}
</style>
