interface Player {
    currentSong: string;
    currentSongLength: number;
    playNext: () => void;
    playPrevious: () => void;
}

const player: Player= {
    currentSong: "Believer",
    currentSongLength: 35_000,
    playNext: () => console.log('Playing next song'),
    playPrevious: () => console.log('Playing previous song')
}

type song = {name: string; length: number};


class AudioPlayer implements Player{
    currentSong: string;
    currentSongLength: number;
    constructor(songInfo: song){
        this.currentSong = songInfo.name;
        this.currentSongLength = songInfo.length;
    }
    playNext= () => console.log('Playing next song');
    playPrevious= () => console.log('Playing previous song');
    stopAudio= () => {};
}

const audioPlayer = new AudioPlayer({name: "shape of you", length: 40_000});
const audioPlayer2 = new AudioPlayer({name: "closer", length: 50_000});

console.log(audioPlayer.currentSong, audioPlayer.currentSongLength)
console.log(audioPlayer2.currentSong, audioPlayer2.currentSongLength)