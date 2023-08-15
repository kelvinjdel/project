var player = {
    currentSong: "Believer",
    currentSongLength: 35000,
    playNext: function () { return console.log('Playing next song'); },
    playPrevious: function () { return console.log('Playing previous song'); }
};
var AudioPlayer = /** @class */ (function () {
    function AudioPlayer(songInfo) {
        this.playNext = function () { return console.log('Playing next song'); };
        this.playPrevious = function () { return console.log('Playing previous song'); };
        this.stopAudio = function () { };
        this.currentSong = songInfo.name;
        this.currentSongLength = songInfo.length;
    }
    return AudioPlayer;
}());
var audioPlayer = new AudioPlayer({ name: "shape of you", length: 40000 });
var audioPlayer2 = new AudioPlayer({ name: "closer", length: 50000 });
console.log(audioPlayer.currentSong, audioPlayer.currentSongLength);
console.log(audioPlayer2.currentSong, audioPlayer2.currentSongLength);
