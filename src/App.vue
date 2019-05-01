<template>
  <div id="app">
    <img alt="Vue logo" src="./assets/logo.png">
    <initialisation msg="Welcomeeee to Your Vue.js App"/>
  </div>
</template>

<script>
import Initialisation from './components/Initialisation.vue'

export default {
  name: 'app',
  components: {
    Initialisation
  }
}
</script>

<style>
#app {
  font-family: 'Avenir', Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
  margin-top: 60px;
}
</style>
