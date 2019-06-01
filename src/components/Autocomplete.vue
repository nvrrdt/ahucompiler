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
  </div>
</template>

<script>
  export default {
    name: 'Autocomplete',
    props: {
      /* items: {
        type: Array,
        required: false,
        default: () => [],
      }, */
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
        showHumidifier: false,
        prevResult: '',
        items: ['Register', 'Filter', 'Recuperation', 'Empty section', 'Coil', 'Fan', 'Humidifier', 'Done']
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
          this.cmpPrevResult()
          this.prevResult = this.search
          this.$parent.$emit('onAddFormElement', 'Register')
        } else if (this.search === 'Filter') {
          console.log('Filter')
          this.cmpPrevResult()
          this.prevResult = this.search
          this.$parent.$emit('onAddFormElement', 'Filter1')
        } else if (this.search === 'Recuperation') {
          console.log('Recuperation')
          this.cmpPrevResult()
          this.prevResult = this.search
          this.$parent.$emit('onAddFormElement', 'Recuperation')
        } else if (this.search === 'Empty section') {
          console.log('Empty')
          this.cmpPrevResult()
          this.prevResult = this.search
          this.$parent.$emit('onAddFormElement', 'EmptySection')
        } else if (this.search === 'Coil') {
          console.log('Coil')
          this.cmpPrevResult()
          this.prevResult = this.search
          this.$parent.$emit('onAddFormElement', 'Coil')
        } else if (this.search === 'Fan') {
          console.log('Fan')
          this.cmpPrevResult()
          this.prevResult = this.search
          this.$parent.$emit('onAddFormElement', 'Fan')
        } else if (this.search === 'Humidifier') {
          console.log('Humidifier')
          this.cmpPrevResult()
          this.prevResult = this.search
          this.$parent.$emit('onAddFormElement', 'Humidifier')
        }
      },
      cmpPrevResult() {
        if (this.prevResult === 'Register') {
          console.log('Register2')
          this.$parent.$emit('onDelFormElement')
        } else if (this.prevResult === 'Filter') {
          console.log('Filter2')
          this.$parent.$emit('onDelFormElement')
        } else if (this.prevResult === 'Recuperation') {
          console.log('Recuperation2')
          this.$parent.$emit('onDelFormElement')
        } else if (this.prevResult === 'Empty section') {
          console.log('Empty2')
          this.$parent.$emit('onDelFormElement')
        } else if (this.prevResult === 'Coil') {
          console.log('Coil2')
          this.$parent.$emit('onDelFormElement')
        } else if (this.prevResult === 'Fan') {
          console.log('Fan2')
          this.$parent.$emit('onDelFormElement')
        } else if (this.prevResult === 'Humidifier') {
          console.log('Humidifier2')
          this.$parent.$emit('onDelFormElement')
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
  }
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