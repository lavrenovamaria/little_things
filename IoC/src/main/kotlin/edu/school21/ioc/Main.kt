package edu.school21.ioc

import edu.school21.ioc.music.Music
import edu.school21.ioc.music.MusicPlayer
import org.springframework.context.support.ClassPathXmlApplicationContext

object TestSpring {
    @JvmStatic
    fun main(args: Array<String>) {
        val context = ClassPathXmlApplicationContext(
            "applicationContext.xml"
        )
        //val musicPlayer: MusicPlayer = context.getBean("musicPlayer", MusicPlayer::class.java)
        val musicPlayer: MusicPlayer = context.getBean("musicPlayer", MusicPlayer::class.java)
        musicPlayer.playMusic()
        context.close()
    }
}