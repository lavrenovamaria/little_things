package edu.school21.ioc.music

class MusicPlayer {

        private var music: Music? = null

        constructor(music: Music) {

            this.music = music

        }

        fun playMusic() {

            println("Playing: " + music!!.getSong())

        }

}