node {
    def server = Artifactory.server "jfrogeval"
    def conanClient = Artifactory.newConanClient()
    def buildInfo
    
    stage ('Artifactory configuration') {
        withEnv(['CONAN_REVISIONS_ENABLED=1']) {
            String remoteName = conanClient.remote.add server: server, repo: "conan-local"
            buildInfo = Artifactory.newBuildInfo()
            buildInfo.project = 'x02'
        }
    }
    
    stage ('Git Clone') {
        git url: 'https://github.com/sr-ota/conan-jfrog', branch: 'main'
    }
    
    stage ('Conan install') {
        withEnv(['CONAN_REVISIONS_ENABLED=1']) {
            buildInfo = conanClient.run command: "install --build missing .", buildInfo: buildInfo
        }
    }

    stage ('Publish build info') {
        server.publishBuildInfo buildInfo
    }
}

