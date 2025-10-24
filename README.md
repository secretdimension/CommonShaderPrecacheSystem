# CommonShaderPrecacheSystem
A small plugin to hold up CommonLoadingScreen if there are shaders precompiling

Adds a Game Instance subsystem called `CommonShaderPrecacheSubsystem` which has the following API:

```c++
// Exposes FShaderPipelineCache::NumPrecompilesRemaining to blueprint callers
UFUNCTION(BlueprintCallable, BlueprintPure)
virtual int32 GetNumPrecompilesRemaining() const;

/*
 * Set whether or not to override this subsystem and *not* hold the loading screen even if there are pre-compiles.
 * This is useful if you are in an open-world scenario and don't want pre-compiles after the initial load-in.
 * OR you could leave this on and instead have your loading screen act as a way to detect shader hitches.
 */
UFUNCTION(BlueprintCallable)
virtual void SetEnabled(bool bInEnabled);
```