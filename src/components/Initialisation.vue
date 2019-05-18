<template>
  <div>
    <h1>{{ msg }}</h1>
    <div class="row justify-content-center">
      <div class="col-4">
        <b-form-input id="range-1" v-model="value1" type="text" readonly>Project number</b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="range-2" v-model="value2" type="text" placeholder="Enter your name" autofocus tabindex="1"></b-form-input>
      </div>
    </div>
    <div class="row justify-content-center">
      <div class="col-4">
        <b-form-input id="range-1" v-model="value1" type="text" readonly>Client</b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="range-2" v-model="value2" type="text" placeholder="Enter your name" tabindex="2"></b-form-input>
      </div>
    </div>
    <div class="row justify-content-center">
      <div class="col-4">
        <b-form-input id="range-1" v-model="value1" type="text" readonly>Project name</b-form-input>
      </div>
      <div class="col-8">
        <b-form-input id="range-2" v-model="value2" type="text" placeholder="Enter your name" tabindex="3"></b-form-input>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  name: 'Initialisation',
  props: {
    msg: String
  },
  data: function() {
    return {
      value1: 'test'
    }
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped>

</style>
