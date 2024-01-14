<script setup>
import { ref, onMounted } from 'vue'

// 响应式状态
const count = ref(0)

// 用来修改状态、触发更新的函数
function increment() {
  count.value++
  console.log("Hello world")
}

// 生命周期钩子
</script>

<template>
  <button @click="increment">Count is: {{ count }}</button>
</template>