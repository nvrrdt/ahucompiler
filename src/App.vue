<template>
  <div id="app">
    <div class="row justify-content-center">
      <div class="col-6">
        <component v-for="(field, index) in fields" v-bind:is="field" :key="index"></component>
      </div>
    </div>
  </div>
</template>

<script>
import GlobalInitialisation from './components/GlobalInitialisation.vue'
import UnitInitialisation from './components/UnitInitialisation.vue';
import Autocomplete from './components/Autocomplete.vue';
import Register from './components/Register.vue';
import Filter1 from './components/Filter.vue';
import Recuperation from './components/Recuperation.vue';
import EmptySection from './components/EmptySection.vue';
import Coil from './components/Coil.vue';
import Fan from './components/Fan.vue';
import Humidifier from './components/Humidifier.vue';

export default {
  name: 'app',
  components: {
    GlobalInitialisation,
    UnitInitialisation,
    Autocomplete,
    Register,
    Filter1,
    Recuperation,
    EmptySection,
    Coil,
    Fan,
    Humidifier
  },
  data: function() {
    return {
      fields: [GlobalInitialisation]
    }
  },
  methods: {
  },
  mounted: function () {
    this.$on('onAddFormElement', function(type) {
      this.fields.push(type)
    })

    this.$on('onDelFormElement', function() {
      this.fields.pop()
    })
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
</style>
