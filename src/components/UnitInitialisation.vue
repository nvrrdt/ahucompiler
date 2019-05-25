<template>
  <div>
    <div class="row">
      <div class="col">
        <h5 class="text-left">Ahu 1 settings:</h5>
      </div>
    </div>
    <div class="row">
      <div class="col-4">
        <b-form-input id="keyAhuName" v-model="keyAhuName" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valAhuName" v-model="valAhuName" type="text" autofocus tabindex="4"></b-form-input>
      </div>
    </div>
    <div class="row">
      <div class="col-4">
        <b-form-input id="keyTypeAhu" v-model="keyTypeAhu" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valTypeAhu" v-model="valTypeAhu" type="text" tabindex="5"></b-form-input>
      </div>
    </div>
    <div class="row">
      <div class="col-4">
        <b-form-input id="keyAirFlowSupply" v-model="keyAirFlowSupply" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valAirFlowSupply" v-model="valAirFlowSupply" type="text" tabindex="6"></b-form-input>
      </div>
    </div>
    <div class="row">
      <div class="col-4">
        <b-form-input id="keyPressureSupply" v-model="keyPressureSupply" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valPressureSupply" v-model="valPressureSupply" type="text" tabindex="7"></b-form-input>
      </div>
    </div>
    <div class="row">
      <div class="col-4">
        <b-form-input id="keyAirFlowReturn" v-model="keyAirFlowReturn" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valAirFlowReturn" v-model="valAirFlowReturn" type="text" tabindex="8"></b-form-input>
      </div>
    </div>
    <div class="row">
      <div class="col-4">
        <b-form-input id="keyPressureReturn" v-model="keyPressureReturn" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valPressureReturn" v-model="valPressureReturn" type="text" tabindex="9"></b-form-input>
      </div>
    </div>
        <div class="row">
      <div class="col-4">
        <b-form-input id="keyCasingType" v-model="keyCasingType" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valCasingType" v-model="valCasingType" type="text" tabindex="10"></b-form-input>
      </div>
    </div>
        <div class="row">
      <div class="col-4">
        <b-form-input id="keyExternalFinish" v-model="keyExternalFinish" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valExternalFinish" v-model="valExternalFinish" type="text" tabindex="11"></b-form-input>
      </div>
    </div>
        <div class="row">
      <div class="col-4">
        <b-form-input id="keyInternalFinish" v-model="keyInternalFinish" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valInternalFinish" v-model="valInternalFinish" type="text" tabindex="12"></b-form-input>
      </div>
    </div>
        <div class="row">
      <div class="col-4">
        <b-form-input id="keyFloorFinish" v-model="keyFloorFinish" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valFloorFinish" v-model="valFloorFinish" type="text" tabindex="13"></b-form-input>
      </div>
    </div>
        <div class="row">
      <div class="col-4">
        <b-form-input id="keyCasingDimsSupply" v-model="keyCasingDimsSupply" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valCasingDimsSupply" v-model="valCasingDimsSupply" type="text" tabindex="14"></b-form-input>
      </div>
    </div>
        <div class="row">
      <div class="col-4">
        <b-form-input id="keyCasingDimsReturn" v-model="keyCasingDimsReturn" type="text" readonly></b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="valCasingDimsReturn" v-model="valCasingDimsReturn" type="text" tabindex="15" @keydown="toAssemble()"></b-form-input>
      </div>
    </div>
    <hr>
  </div>
</template>

<script>
export default {
  name: 'UnitInitialisation',
  data: function() {
    return {
      keyAhuName: 'Ahu name:',
      valAhuName: '',
      keyTypeAhu: 'Type ahu:',
      valTypeAhu: '',
      keyAirFlowSupply: 'Air flow supply:',
      valAirFlowSupply: '',
      keyPressureSupply: 'Ext. pressure supply:',
      valPressureSupply: '',
      keyAirFlowReturn: 'Air flow return:',
      valAirFlowReturn: '',
      keyPressureReturn: 'Ext. pressure return:',
      valPressureReturn: '',
      keyCasingType: 'Type of casing:',
      valCasingType: '',
      keyExternalFinish: 'External finish:',
      valExternalFinish: '',
      keyInternalFinish: 'Internal finish:',
      valInternalFinish: '',
      keyFloorFinish: 'Finish of floor:',
      valFloorFinish: '',
      keyCasingDimsSupply: 'Casing dimensions supply:',
      valCasingDimsSupply: '',
      keyCasingDimsReturn: 'Casing dimensions return:',
      valCasingDimsReturn: ''
    }
  },
  methods: {
    toAssemble: function () {
      console.log('test')
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
