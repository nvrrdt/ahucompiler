<template>
  <div>
    <div class="row">
      <div class="col">
        <h3 class="text-left">Ahu 1 settings:</h3>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyAhuName }}</span>
      </div>
      <div class="col-9">
        <span id="valAhuName" contenteditable="true" @keyup="updateInputAhuName"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyTypeAhu }}</span>
      </div>
      <div class="col-9">
        <span id="valTypeAhu" contenteditable="true" @keyup="updateInputTypeAhu"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyAirFlowSupply }}</span>
      </div>
      <div class="col-9">
        <span id="valAirFlowSupply" contenteditable="true" @keyup="updateInputAirFlowSupply"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyPressureSupply }}</span>
      </div>
      <div class="col-9">
        <span id="valPressureSupply" contenteditable="true" @keyup="updateInputPressureSupply"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyAirFlowReturn }}</span>
      </div>
      <div class="col-9">
        <span id="valAirFlowReturn" contenteditable="true" @keyup="updateInputAirFlowReturn"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyPressureReturn }}</span>
      </div>
      <div class="col-9">
        <span id="valPressureReturn" contenteditable="true" @keyup="updateInputPressureReturn"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyCasingType }}</span>
      </div>
      <div class="col-9">
        <span id="valCasingType" contenteditable="true" @keyup="updateInputCasingType"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyExternalFinish }}</span>
      </div>
      <div class="col-9">
        <span id="valExternalFinish" contenteditable="true" @keyup="updateInputExternalFinish"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyInternalFinish }}</span>
      </div>
      <div class="col-9">
        <span id="valInternalFinish" contenteditable="true" @keyup="updateInputInternalFinish"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyFloorFinish }}</span>
      </div>
      <div class="col-9">
        <span id="valFloorFinish" contenteditable="true" @keyup="updateInputFloorFinish"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyCasingDimsSupply }}</span>
      </div>
      <div class="col-9">
        <span id="valCasingDimsSupply" contenteditable="true" @keyup="updateInputCasingDimsSupply"></span>
      </div>
    </div>
    <div class="row">
      <div class="col-3">
        <span>{{ keyCasingDimsReturn }}</span>
      </div>
      <div class="col-9">
        <span id="valCasingDimsReturn" contenteditable="true" @keyup="updateInputCasingDimsReturn" @keydown.enter="$parent.$emit('onAddFormElement', 'Autocomplete', 12)"></span>
      </div>
    </div>
    <hr>
  </div>
</template>

<script>
export default {
  name: 'UnitInitialisation',
  props: ['max_tabindex_last_component'],
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
      valCasingDimsReturn: '',
      max_tabindex_last_comp: this.max_tabindex_last_component
    }
  },
  methods: {
    updateInputAhuName: function () {
      this.valAhuName = document.getElementById("valAhuName").innerText
      console.log(this.valAhuName)
    },
    updateInputTypeAhu: function () {
      this.valTypeAhu = document.getElementById("valTypeAhu").innerText
      console.log(this.valTypeAhu)
    },
    updateInputAirFlowSupply: function () {
      this.valAirFlowSupply = document.getElementById("valAirFlowSupply").innerText
      console.log(this.valAirFlowSupply)
    },
    updateInputPressureSupply: function () {
      this.valPressureSupply = document.getElementById("valPressureSupply").innerText
      console.log(this.valPressureSupply)
    },
    updateInputAirFlowReturn: function () {
      this.valAirFlowReturn = document.getElementById("valAirFlowReturn").innerText
      console.log(this.valAirFlowReturn)
    },
    updateInputPressureReturn: function () {
      this.valPressureReturn = document.getElementById("valPressureReturn").innerText
      console.log(this.valPressureReturn)
    },
    updateInputCasingType: function () {
      this.valCasingType = document.getElementById("valCasingType").innerText
      console.log(this.valCasingType)
    },
    updateInputExternalFinish: function () {
      this.valExternalFinish = document.getElementById("valExternalFinish").innerText
      console.log(this.valExternalFinish)
    },
    updateInputInternalFinish: function () {
      this.valInternalFinish = document.getElementById("valInternalFinish").innerText
      console.log(this.valInternalFinish)
    },
    updateInputFloorFinish: function () {
      this.valFloorFinish = document.getElementById("valFloorFinish").innerText
      console.log(this.valFloorFinish)
    },
    updateInputCasingDimsSupply: function () {
      this.valCasingDimsSupply = document.getElementById("valCasingDimsSupply").innerText
      console.log(this.valCasingDimsSupply)
    },
    updateInputCasingDimsReturn: function () {
      this.valCasingDimsReturn = document.getElementById("valCasingDimsReturn").innerText
      console.log(this.valCasingDimsReturn)
    }
  },
  mounted: function () {
    // proceed to next tabindex when pressing enter
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

    // set tabindexes
    document.getElementById("valAhuName").tabIndex = (this.max_tabindex_last_comp + 1).toString()
    document.getElementById("valTypeAhu").tabIndex = (this.max_tabindex_last_comp + 2).toString()
    document.getElementById("valAirFlowSupply").tabIndex = (this.max_tabindex_last_comp + 3).toString()
    document.getElementById("valPressureSupply").tabIndex = (this.max_tabindex_last_comp + 4).toString()
    document.getElementById("valAirFlowReturn").tabIndex = (this.max_tabindex_last_comp + 5).toString()
    document.getElementById("valPressureReturn").tabIndex = (this.max_tabindex_last_comp + 6).toString()
    document.getElementById("valCasingType").tabIndex = (this.max_tabindex_last_comp + 7).toString()
    document.getElementById("valExternalFinish").tabIndex = (this.max_tabindex_last_comp + 8).toString()
    document.getElementById("valInternalFinish").tabIndex = (this.max_tabindex_last_comp + 9).toString()
    document.getElementById("valFloorFinish").tabIndex = (this.max_tabindex_last_comp + 10).toString()
    document.getElementById("valCasingDimsSupply").tabIndex = (this.max_tabindex_last_comp + 11).toString()
    document.getElementById("valCasingDimsReturn").tabIndex = (this.max_tabindex_last_comp + 12).toString()
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>
.row {margin: 10px 0px 0px 0px;}
h1 {margin: 0px 0px 20px 0px;}
</style>
