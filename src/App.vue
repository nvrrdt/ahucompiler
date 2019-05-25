<template>
  <div id="app">
    <div class="row justify-content-center">
      <div class="col-6">
        <global-initialisation/>
      </div>
    </div>
  </div>
</template>

<script>
import GlobalInitialisation from './components/GlobalInitialisation.vue'

export default {
  name: 'app',
  components: {
    GlobalInitialisation
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
  margin-top: 20px;
}
</style>
