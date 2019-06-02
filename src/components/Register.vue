<template>
  <div>
    <div class="row">
      <div class="col-4">
        <b-form-input id="keyDamper" v-model="keyDamper" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valDamper" v-model="valDamper" type="text" autofocus tabindex="17"></b-form-input>
      </div>
    </div>
    <div class="row">
      <div class="col-4">
        <b-form-input id="keyFlexibleConnection" v-model="keyFlexibleConnection" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valFlexibleConnection" v-model="valFlexibleConnection" type="text" tabindex="18"></b-form-input>
      </div>
    </div>
    <div class="row">
      <div class="col-4">
        <b-form-input id="keyPlacementDamper" v-model="keyPlacementDamper" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valPlacementDamper" v-model="valPlacementDamper" type="text" tabindex="19" @keydown.enter="$parent.$emit('onAddFormElement', 'Autocomplete')"></b-form-input>
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
      valPlacementDamper: '',
      showAutocomplete: false,

    }
  },
  methods: {
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

<style>
.row {margin: 15px 0px 0px 0px;}
</style>
