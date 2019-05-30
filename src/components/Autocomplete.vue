<template>
  <div class="autocomplete">
    <b-form-input
      type="text"
      @input="onChange"
      v-model="search"
      @keydown.down="onArrowDown"
      @keydown.up="onArrowUp"
      @keydown.enter="onEnter"
      placeholder="Search component:"
      autofocus
      tabindex="16"
    />
    <ul
      id="autocomplete-results"
      v-show="isOpen"
      class="autocomplete-results"
    >
      <li
        class="loading"
        v-if="isLoading"
      >
        Loading results...
      </li>
      <li
        v-else
        v-for="(result, i) in results"
        :key="i"
        @click="setResult(result)"
        class="autocomplete-result"
        :class="{ 'is-active': i === arrowCounter }"
      >
        {{ result }}
      </li>
    </ul>
    <div>
      <register v-if="showRegister"></register>
    </div>
    <div>
      <filter1 v-if="showFilter"></filter1>
    </div>
    <div>
      <recuperation v-if="showRecuperation"></recuperation>
    </div>
    <div>
      <empty-section v-if="showEmptySection"></empty-section>
    </div>
    <div>
      <coil v-if="showCoil"></coil>
    </div>
    <div>
      <fan v-if="showFan"></fan>
    </div>
    <div>
      <humidifier v-if="showHumidifier"></humidifier>
    </div>
  </div>
</template>

<script>
  import Register from './Register.vue'
  import Filter1 from './Filter.vue'
  import Recuperation from './Recuperation.vue'
  import EmptySection from './EmptySection.vue'
  import Coil from './Coil.vue'
  import Fan from './Fan.vue'
  import Humidifier from './Humidifier.vue'

  export default {
    name: 'autocomplete',
    components: {
      Register,
      Filter1,
      Recuperation,
      EmptySection,
      Coil,
      Fan,
      Humidifier
    },
    props: {
      items: {
        type: Array,
        required: false,
        default: () => [],
      },
      isAsync: {
        type: Boolean,
        required: false,
        default: false,
      },
    },

    data() {
      return {
        isOpen: false,
        results: [],
        search: '',
        isLoading: false,
        arrowCounter: 0,
        showRegister: false,
        showFilter: false,
        showRecuperation: false,
        showEmptySection: false,
        showCoil: false,
        showFan: false,
        showHumidifier: false
      };
    },

    methods: {
      onChange() {
        // Let's warn the parent that a change was made
        this.$emit('input', this.search)

        // Is the data given by an outside ajax request?
        if (this.isAsync) {
          this.isLoading = true
        } else {
          // Let's  our flat array
          this.filterResults()
          this.isOpen = true
        }
      },

      filterResults() {
        // first uncapitalize all the things
        this.results = this.items.filter((item) => {
          return item.toLowerCase().indexOf(this.search.toLowerCase()) > -1
        })
      },
      setResult(result) {
        this.search = result
        this.isOpen = false

        this.onClickAndEnter()
      },
      onArrowDown() {
        if (this.arrowCounter < this.results.length) {
          this.arrowCounter = this.arrowCounter + 1
        }
      },
      onArrowUp() {
        if (this.arrowCounter > 0) {
          this.arrowCounter = this.arrowCounter -1
        }
      },
      onEnter() {
        if (this.arrowCounter < 0) {
          return
        }
        this.search = this.results[this.arrowCounter]
        this.isOpen = false
        this.arrowCounter = -1

        this.onClickAndEnter()
      },
      handleClickOutside(evt) {
        if (!this.$el.contains(evt.target)) {
          this.isOpen = false
          this.arrowCounter = -1
        }
      },
      onClickAndEnter() {
        if (this.search === 'Register') {
          console.log('Register')
          this.showRegister = true
        } else if (this.search === 'Filter') {
          console.log('Filter')
          this.showFilter = true
        } else if (this.search === 'Recuperation') {
          console.log('Recuperation')
          this.showRecuperation = true
        } else if (this.search === 'Empty section') {
          console.log('Empty')
          this.showEmptySection = true
        } else if (this.search === 'Coil') {
          console.log('Coil')
          this.showCoil = true
        } else if (this.search === 'Fan') {
          console.log('Fan')
          this.showFan = true
        } else if (this.search === 'Humidfier') {
          console.log('Humidifier')
          this.showHumidifier = true
        }
      }
    },
    watch: {
      items: function (val, oldValue) {
        // actually compare them
        if (val.length !== oldValue.length) {
          this.results = val
          this.isLoading = false
        }
      },
    },
    mounted() {
      document.addEventListener('click', this.handleClickOutside)
    },
    destroyed() {
      document.removeEventListener('click', this.handleClickOutside)
    }
  };
</script>

<style>
  .autocomplete {
    position: relative;
  }

  .autocomplete-results {
    padding: 0;
    margin: 0;
    border: 1px solid #eeeeee;
    height: 120px;
    overflow: auto;
    width: 100%;
  }

  .autocomplete-result {
    list-style: none;
    text-align: left;
    padding: 4px 2px;
    cursor: pointer;
  }

  .autocomplete-result.is-active,
  .autocomplete-result:hover {
    background-color: #4AAE9B;
    color: white;
  }

</style>